#include "xmatformula.h"
#include <string>
#include <sstream>
#include <cstring>

XmatFormula::XmatFormula(std::string a)
{
    initRoutine(a);
}

XmatFormula::XmatFormula(std::string a,double dd)
{
    initRoutine(a);
    dens=dd;
}


std::vector< XmatFormula::elemPart > XmatFormula::parseFormula(std::string orig)
{
    std::stringstream testie;
    XmatFormula::elemPart temp;
    std::string tt;
    std::vector<XmatFormula::elemPart> parsed;

    int ll = orig.length();

    for(auto i=0;i<ll;i++)
    {
        if(isupper(orig.c_str()[i]))
        {
            testie<<" ";
        }

        if(!iswalpha(orig.c_str()[i]))
        {
            if((i>(0)) && (isalpha(orig.c_str()[i-1])))
            {
                testie<<" ";
            }
        }

        testie<<orig[i];

        if(isupper(orig.c_str()[i]))
        {
            if((i<(ll-1))&&(isupper(orig.c_str()[i+1])))
            {
                testie<<" 1 ";
            }
            else if(i==ll-1)
            {
                testie<<" 1 ";
            }

        }

        if(islower(orig.c_str()[i]))
        {
            if((i<(ll-1))&&(isupper(orig.c_str()[i+1])))
            {
                testie<<" 1 ";
            }
            else if(i==ll-1)
            {
                testie<<" 1 ";
            }
        }


    }

    std::string elem;

    while(!testie.eof())
    {
        tt.clear();
        temp.elem.clear();
        testie>>temp.elem;
        testie>>tt;
        if(temp.elem.length()>0)
        {
            temp.num=1;
            temp.num=std::stod(tt);
            parsed.push_back(temp);
        }
    }

    return parsed;
}


void    XmatFormula::initRoutine(std::string a)
{
    elemMix = parseFormula(a);


    std::vector< Xmat> mats;
    double sigma = 0.00000001;
    std::vector< double> ens;
    std::vector< double> edges;
    int i,j,k;
    double ensold;
    double x,y,z;
    std::vector<double> temp;

    for(unsigned(i)=0;i<elemMix.size();i++)
    {
        mats.push_back(Xmat(elemMix[i].elem));

    }

    for( unsigned(j) = 0;j<mats[0].xdd.size();j++)
    {
        ens.push_back(mats[0].xdd[j][0]);
    }

    if(mats[0].xdd.size()>1)
    {
        for(unsigned(i)=1;i<mats.size();i++)
        {
            k=0;
            while(unsigned(k)<(ens.size()-1))
            {
                ensold = 0;

                for(unsigned(j) = 0;j<mats[i].xdd.size();j++)
                {
                    if((ens[k] < mats[i].xdd[j][0]) && (ens[k+1] > mats[i].xdd[j][0]))
                    {
                        ens.insert((ens.begin()+k+1),mats[i].xdd[j][0]);

                        if((unsigned(j)<(mats[i].xdd.size()-1))&&(mats[i].xdd[j+1][0]==mats[i].xdd[j][0]))
                        {
                           ens.insert((ens.begin()+k+1),mats[i].xdd[j][0]);
                        }
                    }


                }
            k++;
            }
        }
    }


//     // determine total atomic mass
    atomMass=0;
    for(unsigned(i)=0;i<mats.size();i++)
    {
        atomMass += (mats[i].atomMass)*elemMix[i].num;
        //std::cout<<"amass"<<atomMass<<std::endl;
    }

//    //density by mass fraction of mixture - unreliable, but better than nothing
    dens = 0;
    for(unsigned(i)=0;i<mats.size();i++)
    {
        dens+=(((mats[i].atomMass)*elemMix[i].num)/atomMass)*mats[i].dens;
        //std::cout<<"atom Mass "<<mats[i].atomMass <<" number: "<<elemMix[i].num<<std::endl;
    }
//    //Populate the xdd (energy, mac, meac) vector
    ensold=0;
    for(unsigned(i)=0;i<ens.size();i++)
    {
        temp.clear();
        y=0;
        z=0;
        x=ens[i];

        for(unsigned(j)=0;j<mats.size();j++)
        {
            if(ens[i]!=ensold)
            {
                y+=(((mats[j].atomMass)*elemMix[j].num)/atomMass)*mats[j].mac(ens[i]);
                z+=(((mats[j].atomMass)*elemMix[j].num)/atomMass)*mats[j].meac(ens[i]);
            }
            else
            {
                y+=((mats[j].atomMass*elemMix[j].num)/atomMass)*mats[j].mac(ens[i]+sigma);
                z+=((mats[j].atomMass*elemMix[j].num)/atomMass)*mats[j].meac(ens[i]+sigma);
            }

        }
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);

        xdd.push_back(temp);
        ensold = ens[i];

    }

}
