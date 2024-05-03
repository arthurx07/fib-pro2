// alvaro.gabriel.diaz@estudiantat.upc.edu L61
// artur.leivar@estudiantat.upc.edu L32

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
    if (nest >= MAX_NEST)
    {
        cerr << "Conjunt ple" << endl;
    }
    else {
        int pos = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
        if (pos < nest and vest[pos].consultar_DNI() == est.consultar_DNI())
            b = true;
        else
        {
            // vest.insert(vest.begin() + i); (fails in efficency tests)
            for (int i = nest - 1; i >= pos; --i)
            {
                vest[i+1] = vest[i];
            }

            vest[pos] = est;
            b = false;
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
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    if (pos < nest and vest[pos].consultar_DNI() == dni)
    {
        if (vest[pos].te_nota())
        {
            decrementar_interval(vest[pos].consultar_nota());
        }

        // vest.erase(vest.begin() + i); (fails in efficency tests)
        for (int i = pos; i < nest - 1; ++i)
        {
            vest[i] = vest[i+1];
        }
        vest[nest - 1] = Estudiant();
        b = true;
        --nest;
    }
    else
    {
        b = false;
    }
}

void Cjt_estudiants::incrementar_interval(double x)
{
    int interval;
    if (x < 10)
    {
        interval = int(x);
    }
    else
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
    else
    {
        interval = 9;
    }
    --intervals[interval];
}
