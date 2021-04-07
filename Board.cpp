#include "Board.hpp"


    ariel::Board::Board()
    {
        x = y = 0;
        ch.push_back(vector<char>(1,'_'));
    }

    void ariel::Board::post(unsigned int r, unsigned int c, Direction type, string str)
    {
        unsigned int i,j;
        if (str.length() == 0)
        {
            return;
        }

        if (type == H)
        {
            if (r > y)
            {
                i = (r-y);
                while(i)
                {
                    ch.push_back(vector<char>(ch.at(0).size(),'_'));
                    i--;
                }
                y = ch.size() - 1;
            }

            if (c + str.length() > x)
            {
               
                i=0;
                while(i<ch.size())
                {
                    j = c - x + str.length() - 1;
                    while(j)
                    {
                        ch.at(i).push_back('_');
                        j--;
                    }
                    i++;
                }
                x = ch.at(0).size() - 1;
                
            }
        }
        else
        {
            if (r + str.length() > y)
            {
                i = r - y + str.length() - 1;
                while(i)
                {
                    ch.push_back(vector<char>(ch.at(0).size(),'_'));
                    i--;
                }
                y = ch.size() - 1;
                
            }
            if (c > x)
            {
                i=0;
                while(i<ch.size())
                {
                    j = c - x;
                    while(j)
                    {
                        ch.at(i).push_back('_');
                        j--;
                    }
                    i++;
                }
                x = ch.at(0).size() - 1;
                
            }
        }
        
        i = 0;
        while(i<str.length())
        {
            
            if (type == H)
            {
                ch.at(r).at(c + i) = str.at(i);
            }
            else
            {
                ch.at(r + i).at(c) = str.at(i);
            }
            i++;
        }
    }

    string ariel::Board::read(unsigned int r, unsigned int c, Direction type, unsigned int size)
    {
        

        if (size == 0)
            return "";

        unsigned int ch_s = size, sz=size, _s_=0, i=0;
        string str;

        if ((r > y) || (c > x))
        {
            while(sz)
            {
                str+='_';
                sz--;
            }
            return str;
        }

        if (r + size > y && type == V)
        {
            _s_ = r + size - y - 1;
        }
        else if (c + size > x && type == H)
        {
            _s_ = c + size - x - 1;
        }
        ch_s = size - _s_;
        
        while (i<ch_s)
        {
            if (type == V)
            {
                str += ch.at(r + i).at(c);
            }
            else
            {
                str += ch.at(r).at(c + i);
            }
            i++;
        }

        while(_s_)
        {
           str += '_';
           _s_--; 
        }

        return str;
    }

    void ariel::Board::show()
    {
        unsigned int i=0,j=0;
        while(i<ch.size())
        {   
            cout<<i<<":  ";
            while(j<ch.at(0).size())
            {
                cout << ch.at(i).at(j);
                j++;
            }
            cout<<endl;
            j=0;
            i++;

        }


        
    }
