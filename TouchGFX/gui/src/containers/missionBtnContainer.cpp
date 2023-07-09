#include <gui/containers/missionBtnContainer.hpp>

missionBtnContainer::missionBtnContainer()
{

}

void missionBtnContainer::initialize()
{
    missionBtnContainerBase::initialize();
}

void missionBtnContainer::setText(TEXTS text) {
    textArea1.setTypedText(touchgfx::TypedText(text));
    textArea1.invalidate();
}

/* The clicklistener of TouchGFX buttons prevents the scrollList from ever receiving click events...
    Here comes this DIY button... Forgive me. */
void missionBtnContainer::doClickAnimation() {
    animatedImage1.startAnimation(true, true, false);
}