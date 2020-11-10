#include <iostream>

char* removeDups(char str[])
{
    bool bin_hash[256] = { 0 };
    int ip_ind = 0, res_ind = 0;
    char temp;

    /* In place removal of duplicate characters*/
    while (*(str + ip_ind))
    {
        temp = *(str + ip_ind);
        if (bin_hash[temp] == 0)
        {
            bin_hash[temp] = 1;
            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }

    /* After above step string is stringiittg.
        Removing extra iittg after string*/
    *(str + res_ind) = '\0';

    return str;
}

//int main()
//{
//    char str[] = "geeksforgeeks";
//    std::string result = removeDups(str);
//}