#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int zlicz_zaglowce = 0;
    unsigned int przetransportowany = 0;
    if (towar == 0) {return 0;}
    else{
      while (przetransportowany < towar)
      {
        Stocznia stocznia{};
        Statek* s1 = stocznia();
        przetransportowany = przetransportowany + s1->transportuj();
        if (s1 == dynamic_cast<Zaglowiec*>(s1))
        {
          zlicz_zaglowce++;
        }
        delete s1;
      }
    }
    return zlicz_zaglowce;
}