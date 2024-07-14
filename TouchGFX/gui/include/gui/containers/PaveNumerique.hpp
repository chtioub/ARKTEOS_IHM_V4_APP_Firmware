#ifndef PAVENUMERIQUE_HPP
#define PAVENUMERIQUE_HPP

#include <gui_generated/containers/PaveNumeriqueBase.hpp>

class PaveNumerique : public PaveNumeriqueBase
{
public:
    PaveNumerique();
    virtual ~PaveNumerique() {}

    virtual void initialize();
protected:
};

#endif // PAVENUMERIQUE_HPP
