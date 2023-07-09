#ifndef MISSIONBTNCONTAINER_HPP
#define MISSIONBTNCONTAINER_HPP

#include <gui_generated/containers/missionBtnContainerBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

class missionBtnContainer : public missionBtnContainerBase
{
public:
    missionBtnContainer();
    virtual ~missionBtnContainer() {}

    virtual void initialize();

    void setText(TEXTS text);

    void doClickAnimation();
protected:
};

#endif // MISSIONBTNCONTAINER_HPP
