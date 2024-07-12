#include <iostream>
#include <vector>

class ParticleSystem {
    struct Particle {
        float x {0.0f};
        float y {0.0f};
        float z {0.0f};
        float speed {0.0f};
        float lifetime {0.0f};

        void Move(){/*move particles*/}
    };
    public:
    void Simulation(){
        for(auto& elem : m_particles){
            elem.Move();
        }
    }
    private:
    std::vector<Particle> m_particles;
};

int main(){
    //ParticleSystem::Particle individualparticle;
    ParticleSystem p;
    p.Simulation();
    return 0;
}

 