#include <SFML/Graphics.hpp>
#include "game.h"
#include <chrono>
#include <condition_variable>

static std::condition_variable cv;
static std::mutex mut;


int main()
{
    //INIT GAME
    Game game;
    using delta = std::chrono::duration<std::int64_t, std::ratio<1, 60>>;
    auto next = std::chrono::steady_clock::now() + delta{1};
    std::unique_lock<std::mutex> lk(mut);
    while (game.running())
    {   
        mut.unlock();
        game.run();
        mut.lock();

        cv.wait_until(lk, next, []{return false;});
        next += delta{1};
    }

    return 0;
}
