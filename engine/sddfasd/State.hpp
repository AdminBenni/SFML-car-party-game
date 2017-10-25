#ifndef STATE_HPP
#define STATE_HPP

#include <string>

namespace bEngine
{
        class State
        {
        public:
            virtual void Init() = 0;

            virtual void Input() = 0;
            virtual void Update(float dt) = 0;
            virtual void Draw(float dt) = 0;

            virtual void Pause() {}
            virtual void Resume() {}
        };
}
#endif // STATE_HPP
