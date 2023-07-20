#include <stdio.h>
int main()
{
    char ch;
    int maxx_c[26] = {0};
    int maxx_v[26] = {0};
    int sec_maxx_c[26] = {0};
    int sec_maxx_v[26] = {0};
    int v_maxx = -1, v_sec = -1;
    int c_maxx = -1, c_sec = -1;
    int vowel[26] = {0};
    int consonant[26] = {0};
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            vowel[ch - 'a']++;
        }
        else
        {
            consonant[ch - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (consonant[i] == c_maxx)
        {
            continue;
        }
        else if (consonant[i] > c_maxx)
        {
            c_sec = c_maxx;
            c_maxx = consonant[i];
        }
        else if (consonant[i] > c_sec)
        {
            c_sec = consonant[i];
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (vowel[i] == v_maxx)
        {
            continue;
        }
        else if (vowel[i] > v_maxx)
        {
            v_sec = v_maxx;
            v_maxx = vowel[i];
        }
        else if (vowel[i] > v_sec)
        {
            v_sec = vowel[i];
        }
    }
    if (v_maxx <= 0 || v_sec <= 0 || c_maxx <= 0 || c_sec <= 0)
    {
        printf("“Warning!! Insufficient Text!!\n");
    }
    else
    {
        for (int i = 0; i < 26; ++i)
        {
            if (consonant[i] == c_maxx)
            {
                maxx_c[i] = 1;
            }
            else if (consonant[i] == c_sec)
            {
                sec_maxx_c[i] = 1;
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            if (vowel[i] == v_maxx)
            {
                maxx_v[i] = 1;
            }
            else if (vowel[i] == v_sec)
            {
                sec_maxx_v[i] = 1;
            }
        }
        if (c_sec > v_sec)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (maxx_c[i] == 0)
                {
                    continue;
                }
                for (int j = 0; j < 26; ++j)
                {
                    if (maxx_v[j] == 0)
                    {
                        continue;
                    }
                    for (int k = 0; k < 26; ++k)
                    {
                        if (sec_maxx_c[k] == 0)
                        {
                            continue;
                        }
                        for (int l = 0; l < 26; ++l)
                        {
                            if (sec_maxx_v[l] == 0)
                            {
                                continue;
                            }
                            if(v_sec==c_sec){
                                
                            }
                            printf("%c%c%c%c\n", 'a' + i, 'a' + j, 'a' + k, 'a' + l);
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 26; ++i)
            {
                if (maxx_c[i] == 0)
                {
                    continue;
                }
                for (int j = 0; j < 26; ++j)
                {
                    if (maxx_v[j] == 0)
                    {
                        continue;
                    }
                    for (int k = 0; k < 26; ++k)
                    {
                        if (sec_maxx_v[k] == 0)
                        {
                            continue;
                        }
                        for (int l = 0; l < 26; ++l)
                        {
                            if (sec_maxx_c[l] == 0)
                            {
                                continue;
                            }
                            printf("%c%c%c%c\n", 'a' + i, 'a' + j, 'a' + k, 'a' + l);
                        }
                    }
                }
            }
        }
    }
    return 0;
}