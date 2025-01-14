#include <iostream>
#include <vector>

// Constants
const float GRAVITY = 9.81f;
const int NUM_PARTICLES = 10000;

class Particle {
public:
    float x, y, vx, vy, density, pressure;
    bool liquid;

    Particle(float _x, float _y) : x(_x), y(_y), vx(0.f), vy(0.f), density(1.f), pressure(0.f), liquid(true) {}
};

class FluidSim {
public:
    std::vector<Particle> particles;
    float timeStep = 0.01f;

    void init() {
        for (int i = 0; i < NUM_PARTICLES; ++i) {
            Particle p(i / static_cast<float>(NUM_PARTICLES), i % static_cast<float>(NUM_PARTICLES));
            particles.push_back(p);
        }
    }

    void simulate(float dt) {
        timeStep = dt;

        for (auto& p : particles) {
            // Compute velocities
            p.vx += dt * GRAVITY;
            p.vy -= 0.01f * (p.y - NUM_PARTICLES / 2.f);

            // Update positions
            p.x += p.vx * timeStep;
            p.y += p.vy * timeStep;

            // Apply boundary conditions (simple bounce off walls)
            if (p.x < 0 || p.x >= 1) {
                p.vx = -p.vx;
            }
            if (p.y < 0 || p.y >= 1) {
                p.vy = -p.vy;
            }

            // Compute density and pressure (very simplified for this example)
            p.density = 1.f;
            p.pressure = p.density * GRAVITY;
        }
    }

    void render() {
        std::cout << "Rendering frame..." << std::endl;

        for (const auto& p : particles) {
            if (p.liquid) {
                std::cout << "L" << p.x << "," << p.y << " ";
            } else {
                std::cout << "." << p.x << "," << p.y << " ";
            }
        }

        std::cout << "\n";
    }

    void run() {
        init();

        for (float t = 0; t < 10.f; t += timeStep) {
            simulate(timeStep);
            render();
            // Add a small delay to make it visible
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

int main() {
    FluidSim fluid;
    fluid.run();

    return 0;
}