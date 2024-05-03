// alvaro.gabriel.diaz@estudiantat.upc.edu L61
// artur.leivar@estudiantat.upc.edu L32

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
    if (nest < MAX_NEST)
    {
        int i = nest - 1;
        int dni = est.consultar_DNI();

        if (cerca_dicot(vest, 0, nest - 1, dni) == -1)
        {
            while (i >= 0 and dni < vest[i].consultar_DNI())
            {
                vest[i + 1] = vest[i];
                --i;
            }

            b = false;
            vest[i + 1] = est;
            ++nest;
            if (est.te_nota())
            {
                incrementar_interval(est.consultar_nota());
            }
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b)
{
    int i = cerca_dicot(vest, 0, nest - 1, dni);
    if (i == -1) {
        b = false;
    }
    else
    {
        if (vest[i].te_nota())
        {
            decrementar_interval(vest[i].consultar_nota());
        }
        vest.erase(vest.begin() + i);
        --nest;
        b = true;
    }
}

void Cjt_estudiants::incrementar_interval(double x)
{
    int interval;
    if (x < 10)
    {
        interval = int(x);
    }
    else // if (x == 10)
    {
        interval = 9;
    }
    ++intervals[interval];
}

void Cjt_estudiants::decrementar_interval(double x)
{
    int interval;
    if (x < 10)
    {
        interval = int(x);
    }
    else // if (x == 10)
    {
        interval = 9;
    }
    --intervals[interval];
}