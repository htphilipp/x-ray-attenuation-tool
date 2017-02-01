#pragma once

#ifndef XMAT_H
#define XMAT_H

//#include "xmat_global.h"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>


class Xmat
{
public:

    Xmat();
    Xmat(std::string a);

    double mac(double);       //Return the mass attenuation coefficient.  Input photon energy (keV), return cm^2/g mac.
    double meac(double);      //Return the mass energy absorption coefficient.  Input photon energy (keV), return cm^2/g meac.
    double mfp(double);       // return the mrean free path using the mac and the default element density, or passed density.
    double mfp(double,double);
    double mfpunit(std::string); // set mfp units, "cm","um","mm","inch","m"
    std::vector< double>    edges();


    std::string mname;
    std::string msymb;
    double dens;
    double atomMass;
    int    elNum;
    double    qmult;  // a mutliplier of one returns the mfp in cm.  The default is cm (1).


    std::vector< std::vector<double> > xdd;

    ~Xmat();

private:
    std::vector< std::vector<std::string> > npt =
    {{"1", "H", "hydrogen", "mhydrogen.dat", "xhydrogen.dat"}, {"2", "He",
      "helium", "mhelium.dat", "xhelium.dat"}, {"3", "Li", "lithium",
      "mlithium.dat", "xlithium.dat"}, {"4", "Be", "beryllium",
      "mberyllium.dat", "xberyllium.dat"}, {"5", "B", "boron", "mboron.dat",
       "xboron.dat"}, {"6", "C", "carbon", "mcarbon.dat",
      "xcarbon.dat"}, {"7", "N", "nitrogen", "mnitrogen.dat",
      "xnitrogen.dat"}, {"8", "O", "oxygen", "moxygen.dat",
      "xoxygen.dat"}, {"9", "F", "fluorine", "mfluorine.dat",
      "xfluorine.dat"}, {"10", "Ne", "neon", "mneon.dat", "xneon.dat"}, {"11",
       "Na", "sodium", "msodium.dat", "xsodium.dat"}, {"12", "Mg",
      "magnesium", "mmagnesium.dat", "xmagnesium.dat"}, {"13", "Al",
      "aluminum", "maluminum.dat", "xaluminum.dat"}, {"14", "Si", "silicon",
       "msilicon.dat", "xsilicon.dat"}, {"15", "P", "phosphorus",
      "mphosphorus.dat", "xphosphorus.dat"}, {"16", "S", "sulfur",
      "msulfur.dat", "xsulfur.dat"}, {"17", "Cl", "chlorine",
      "mchlorine.dat", "xchlorine.dat"}, {"18", "Ar", "argon", "margon.dat",
       "xargon.dat"}, {"19", "K", "potassium", "mpotassium.dat",
      "xpotassium.dat"}, {"20", "Ca", "calcium", "mcalcium.dat",
      "xcalcium.dat"}, {"21", "Sc", "scandium", "mscandium.dat",
      "xscandium.dat"}, {"22", "Ti", "titanium", "mtitanium.dat",
      "xtitanium.dat"}, {"23", "V", "vanadium", "mvanadium.dat",
      "xvanadium.dat"}, {"24", "Cr", "chromium", "mchromium.dat",
      "xchromium.dat"}, {"25", "Mn", "manganese", "mmanganese.dat",
      "xmanganese.dat"}, {"26", "Fe", "iron", "miron.dat",
      "xiron.dat"}, {"27", "Co", "cobalt", "mcobalt.dat",
      "xcobalt.dat"}, {"28", "Ni", "nickel", "mnickel.dat",
      "xnickel.dat"}, {"29", "Cu", "copper", "mcopper.dat",
      "xcopper.dat"}, {"30", "Zn", "zinc", "mzinc.dat", "xzinc.dat"}, {"31",
      "Ga", "gallium", "mgallium.dat", "xgallium.dat"}, {"32", "Ge",
      "germanium", "mgermanium.dat", "xgermanium.dat"}, {"33", "As",
      "arsenic", "marsenic.dat", "xarsenic.dat"}, {"34", "Se", "selenium",
      "mselenium.dat", "xselenium.dat"}, {"35", "Br", "bromine",
      "mbromine.dat", "xbromine.dat"}, {"36", "Kr", "krypton",
      "mkrypton.dat", "xkrypton.dat"}, {"37", "Rb", "rubidium",
      "mrubidium.dat", "xrubidium.dat"}, {"38", "Sr", "strontium",
      "mstrontium.dat", "xstrontium.dat"}, {"39", "Y", "yttrium",
      "myttrium.dat", "xyttrium.dat"}, {"40", "Zr", "zirconium",
      "mzirconium.dat", "xzirconium.dat"}, {"41", "Nb", "niobium",
      "mniobium.dat", "xniobium.dat"}, {"42", "Mo", "molybdenum",
      "mmolybdenum.dat", "xmolybdenum.dat"}, {"43", "Tc", "technetium",
      "mtechnetium.dat", "xtechnetium.dat"}, {"44", "Ru", "ruthenium",
      "mruthenium.dat", "xruthenium.dat"}, {"45", "Rh", "rhodium",
      "mrhodium.dat", "xrhodium.dat"}, {"46", "Pd", "palladium",
      "mpalladium.dat", "xpalladium.dat"}, {"47", "Ag", "silver",
      "msilver.dat", "xsilver.dat"}, {"48", "Cd", "cadmium", "mcadmium.dat",
       "xcadmium.dat"}, {"49", "In", "indium", "mindium.dat",
      "xindium.dat"}, {"50", "Sn", "tin", "mtin.dat", "xtin.dat"}, {"51",
      "Sb", "antimony", "mantimony.dat", "xantimony.dat"}, {"52", "Te",
      "tellurium", "mtellurium.dat", "xtellurium.dat"}, {"53", "I",
      "iodine", "miodine.dat", "xiodine.dat"}, {"54", "Xe", "xenon",
      "mxenon.dat", "xxenon.dat"}, {"55", "Cs", "cesium", "mcesium.dat",
      "xcesium.dat"}, {"56", "Ba", "barium", "mbarium.dat",
      "xbarium.dat"}, {"57", "La", "lanthanum", "mlanthanum.dat",
      "xlanthanum.dat"}, {"58", "Ce", "cerium", "mcerium.dat",
      "xcerium.dat"}, {"59", "Pr", "praseodymium", "mpraseodymium.dat",
      "xpraseodymium.dat"}, {"60", "Nd", "neodymium", "mneodymium.dat",
      "xneodymium.dat"}, {"61", "Pm", "promethium", "mpromethium.dat",
      "xpromethium.dat"}, {"62", "Sm", "samarium", "msamarium.dat",
      "xsamarium.dat"}, {"63", "Eu", "europium", "meuropium.dat",
      "xeuropium.dat"}, {"64", "Gd", "gadolinium", "mgadolinium.dat",
      "xgadolinium.dat"}, {"65", "Tb", "terbium", "mterbium.dat",
      "xterbium.dat"}, {"66", "Dy", "dysprosium", "mdysprosium.dat",
      "xdysprosium.dat"}, {"67", "Ho", "holmium", "mholmium.dat",
      "xholmium.dat"}, {"68", "Er", "erbium", "merbium.dat",
      "xerbium.dat"}, {"69", "Tm", "thulium", "mthulium.dat",
      "xthulium.dat"}, {"70", "Yb", "ytterbium", "mytterbium.dat",
      "xytterbium.dat"}, {"71", "Lu", "lutetium", "mlutetium.dat",
      "xlutetium.dat"}, {"72", "Hf", "hafnium", "mhafnium.dat",
      "xhafnium.dat"}, {"73", "Ta", "tantalum", "mtantalum.dat",
      "xtantalum.dat"}, {"74", "W", "tungsten", "mtungsten.dat",
      "xtungsten.dat"}, {"75", "Re", "rhenium", "mrhenium.dat",
      "xrhenium.dat"}, {"76", "Os", "osmium", "mosmium.dat",
      "xosmium.dat"}, {"77", "Ir", "iridium", "miridium.dat",
      "xiridium.dat"}, {"78", "Pt", "platinum", "mplatinum.dat",
      "xplatinum.dat"}, {"79", "Au", "gold", "mgold.dat", "xgold.dat"}, {"80",
       "Hg", "mercury", "mmercury.dat", "xmercury.dat"}, {"81", "Tl",
      "thallium", "mthallium.dat", "xthallium.dat"}, {"82", "Pb", "lead",
      "mlead.dat", "xlead.dat"}, {"83", "Bi", "bismuth", "mbismuth.dat",
      "xbismuth.dat"}, {"84", "Po", "polonium", "mpolonium.dat",
      "xpolonium.dat"}, {"85", "At", "astatine", "mastatine.dat",
      "xastatine.dat"}, {"86", "Rn", "radon", "mradon.dat",
      "xradon.dat"}, {"87", "Fr", "francium", "mfrancium.dat",
      "xfrancium.dat"}, {"88", "Ra", "radium", "mradium.dat",
      "xradium.dat"}, {"89", "Ac", "actinium", "mactinium.dat",
      "xactinium.dat"}, {"90", "Th", "thorium", "mthorium.dat",
      "xthorium.dat"}, {"91", "Pa", "protactinium", "mprotactinium.dat",
      "xprotactinium.dat"}, {"92", "U", "uranium", "muranium.dat",
      "xuranium.dat"}};

};

#endif // XMAT_H





