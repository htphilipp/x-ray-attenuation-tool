#include "xmat.h"

#include <sstream>

//class xmat_elem_not_recog {};

Xmat::Xmat()
{

}

//"C:\\Users\\Hugh\\Documents\\programming\\Xdat\\xchlorine.dat"

Xmat::Xmat(std::string a)
{
    int i=0;    //index to find cataloged material
    bool g;      //dummy variable
    std::stringstream     inbuf;  //
    //std::string path("C:\\Users\\Hugh\\Documents\\programming\\Xdat\\");
    std::string path(std::getenv("xmatPath"));

    qmult = 1;

    while(i<92)
    {
        g=(!a.compare(npt[i][1]))||(!a.compare(npt[i][2]))||(!a.compare(npt[i][0]));
        if(g)
            break;
        //std::cout<<i;
        i++;
    }

    //std::cout<<npt[i][4];
    if(g)
    {
            std::ifstream *xfi = new std::ifstream(path+npt[i][4]);

            if(!(xfi->good()))
            {
                throw   "file not found - check env. var. xmatPath";
            }

            double x,y,z;
            std::vector<double> temp;

            inbuf << xfi->rdbuf();
            //std::cout<<inbuf.str();

            xfi->close();

            std::cout<<std::endl;

            while(!inbuf.eof())
            {
                temp.clear();
                inbuf>>x>>y>>z;
                //std::cout<<std::endl<<x<<"  "<<y<<"  "<<z;
                temp.push_back(1000*x);
                temp.push_back(y);
                temp.push_back(z);

                xdd.push_back(temp);

            }

            delete xfi;

            inbuf.clear();
            xfi = new std::ifstream(path+npt[i][3]);
            inbuf << xfi->rdbuf();

            inbuf>>elNum>>msymb>>mname>>atomMass>>dens;

            xfi->close();

    }
    else
    {
        //throw xmat_elem_not_recog {};
        throw   "element not recognized";
    }


}

Xmat::~Xmat()
{

}

double Xmat::mac(double en)
{
    int i=0;
    double macout=0;

    if((en>=xdd[0][0])&&(en<=20000))
    {
        while(xdd[i][0]<en)
        {
            i++;
        }

        if(en>xdd[0][0])
        {
        macout = exp(log(xdd[i-1][1])+ ((log(xdd[i][1])-log(xdd[i-1][1]))*(log(en)-log(xdd[i-1][0]))/(log(xdd[i][0])-log(xdd[i-1][0])) ));
        }
        else if(en==xdd[0][0])
        {
            macout = xdd[0][1];
        }

    }
    else
    {
        macout = 0;
        throw   "out of energy range";
    }

    return macout;
}

double Xmat::meac(double en)
{
    int i=0;
    double macout=0;

    if((en>=xdd[0][0])&&(en<=20000))
    {
        while(xdd[i][0]<en)
        {
            i++;
        }

        if(en>xdd[0][0])
        {
        macout = exp(log(xdd[i-1][2])+ ((log(xdd[i][2])-log(xdd[i-1][2]))*(log(en)-log(xdd[i-1][0]))/(log(xdd[i][0])-log(xdd[i-1][0])) ));
        }
        else if(en==xdd[0][0])
        {
            macout = xdd[0][2];
        }

    }
    else
    {
        macout = 0;
        throw   "out of energy range";
    }

    return macout;
}

double Xmat::mfp(double en)  //using stored density
{
    return  qmult/(mac(en)*dens);
}

double Xmat::mfp(double en, double md) // density passed
{
    return  qmult/(mac(en)*md);
}

double Xmat::mfpunit(std::string units)
{
    if(units=="cm")
    {
            qmult=1;
    }
    else if(units=="um")
    {
            qmult=10000;
    }
    else if(units=="mm")
    {
            qmult=10;
    }
    else if(units=="m")
    {
            qmult=0.01;
    }
    else if(units=="inch")
    {
            qmult=1/2.54;
    }

    return qmult;


}

std::vector< double>    Xmat::edges()
{
    std::vector< double>    ens;
    double vo = 0;
    //int i;


    for(unsigned(i)=0; i<xdd.size();i++ )
    {
        if(vo==xdd[i][0])
            ens.push_back(xdd[i][0]);

        vo=xdd[i][0];
    }

    return  ens;
}
