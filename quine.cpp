#include <iostream>
char* f(const char* d)
{
        int size;
        for(size=0;d[size]!=0;size++);
        int len=size*2+2;
        char* c=new char[2*len];
        for(int i=0,p=0;i<=size;i++)
                switch(d[i])
                {
                case 126:
                        for(int j=0;j<size;j++)
                        switch(d[j])
                        {
                                case 9:
                                case 10:
                                case 34:
                                {c[p]=(char)92;p++;}

                                switch(d[j])
                                {
                                        case 9:
                                        {c[p]=(char)116;p++;}
                                        break;
                                        case 10:
                                        {c[p]=(char)110;p++;}
                                        break;
                                        case 34:
                                        {c[p]=(char)34;p++;}
                                        break;
                                }
                                break;
                        default:
                                {c[p]=d[j];p++;}
                        }
                break;
                default:
                {c[p]=d[i];p++;}
                }
        return c;
}

int main()
{
        const char* a="#include <iostream>\nchar* f(const char* d)\n{\n\tint size;\n\tfor(size=0;d[size]!=0;size++);\n\tint len=size*2+2;\n\tchar* c=new char[2*len];\n\tfor(int i=0,p=0;i<=size;i++)\n\t\tswitch(d[i])\n\t\t{\n\t\tcase 126:\n\t\t\tfor(int j=0;j<size;j++)\n\t\t\tswitch(d[j])\n\t\t\t{\n\t\t\t\tcase 9:\n\t\t\t\tcase 10:\n\t\t\t\tcase 34:\n\t\t\t\t{c[p]=(char)92;p++;}\n\t\t\t\t\n\t\t\t\tswitch(d[j])\n\t\t\t\t{\n\t\t\t\t\tcase 9:\n\t\t\t\t\t{c[p]=(char)116;p++;}\n\t\t\t\t\tbreak;\n\t\t\t\t\tcase 10:\n\t\t\t\t\t{c[p]=(char)110;p++;}\n\t\t\t\t\tbreak;\n\t\t\t\t\tcase 34:\n\t\t\t\t\t{c[p]=(char)34;p++;}\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\tdefault:\n\t\t\t\t{c[p]=d[j];p++;}\n\t\t\t}\n\t\tbreak;\n\t\tdefault:\n\t\t{c[p]=d[i];p++;}\n\t\t}\n\treturn c;\n}\n\nint main()\n{\n\tconst char* a=\"~\";\n\tchar* c=f(a);\n\tstd::cout<<c;\n\tstd::cin.ignore();\n\tdelete c;\n\t\n}";
        char* c=f(a);
        std::cout<<c;
        std::cin.ignore();
        delete c;

}
