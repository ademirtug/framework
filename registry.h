#ifndef __REGISTRY_H__
#define __REGISTRY_H__

class registry_key
{
public:
    HKEY hKeyParent,hKey;
    const char* subkey;
    const char* valueName
    bool opened = false;

    registry_key(){}

    registry_key(HKEY _hKeyParent, const char* _subkey, const char* _valueName)
    {
        hKeyParent = _hKeyParent;
        subkey = _subkey;
        valuename = _valuename;

        createopen();
    }
    ~registry_key()
    {
        if(hKey)
            RegCloseKey(hKey);

    }
    bool createopen()
    {
        DWORD dwDisposition, Ret;
        Ret = RegCreateKeyExA(hKeyParent, subkey, 0, NULL, REG_OPTION_NON_VOLATILE,
                KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition);
        if (Ret != ERROR_SUCCESS)
            return false;

        opened = true;
        return true;
    }
    bool write(DWORD data)
    {
        DWORD Ret;
        if(!opened)
            if(!createopen())
            return false;

        if (ERROR_SUCCESS != RegSetValueExA(hKey, valueName,0,REG_DWORD,reinterpret_cast<BYTE*>(&data),sizeof(data)))
            return false;
        return true;
    }
    DWORD readdword(const char* valueName)
    {
        DWORD data;
        DWORD len = sizeof(DWORD);
        Ret = RegQueryValueExA( hKey,valueName, NULL,NULL,(LPBYTE)(&data),&len);

        if (Ret == ERROR_SUCCESS)
            return data;
        throw exception("failed to read registry key data!!!");
    }
}

#endif //__REGISTRY_H__