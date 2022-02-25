#include "lambdas.hh"

#define UNUSED(x) (void)(x)

strategy_type cooperator()
{
    return [](iterator_type b, iterator_type e) {
        UNUSED(b);
        UNUSED(e);
        return true;
    };
}

strategy_type cheater()
{
    return [](iterator_type b, iterator_type e) {
        UNUSED(b);
        UNUSED(e);
        return false;
    };
}

strategy_type copycat()
{
    return [](iterator_type b, iterator_type e) {
        if (*b == *e)
            return true;
        else
        {
            if (*e == 2 || *e == 3)
                return true;
            else
                return false;
        }
    };
}

strategy_type grudger()
{
    return [](iterator_type b, iterator_type e) {
        while (b != e)
        {
            if (*b == 3)
                return false;
        }
        return true;
    };
}
strategy_type detective()
{
    return [](iterator_type b, iterator_type e) {
        if (std::distance(b, e) == 0)
            return true;
        else if (std::distance(b, e) == 1)
            return false;
        else if (std::distance(b, e) == 2 || std::distance(b, e) == 3)
            return true;
        else
        {
            bool have_cheated = false;
            for (int i = 0; i < 4; i++, b++)
            {
                if (i == 0 || i == 2 || i == 3)
                {
                    if (*b == -1)
                    {
                        have_cheated = true;
                        break;
                    }
                }
                else if (*b == 0)
                {
                    have_cheated = true;
                    break;
                }
            }

            if (!have_cheated)
                return false;
            else
            {
                if (*b == *e)
                    return true;
                else
                {
                    if (*e == 2 || *e == 3)
                        return true;
                    else
                        return false;
                }
            }
        }
    };
}

strategy_type copykitten()
{
    return [](iterator_type b, iterator_type e) {
        return false;
    };
}
