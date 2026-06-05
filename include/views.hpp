#ifndef VIEWS_HPP
#define VIEWS_HPP

#include <vector>

#include "./common.hpp"

class MainView : View
{
    /* resources*/
    std::vector<SkImage> animationFrames;

    /* methods */
    void Load() override;
    void Pause() override;
    void Destroy() override;

    void OnInput(const InputEvent& input) override;
    void OnRender(SkCanvas* canvas) override;
};

#endif // VIEWS_HPP