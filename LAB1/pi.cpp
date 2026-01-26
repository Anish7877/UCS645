#include <chrono>
#include <print>
#include <ratio>

int main(){
        constexpr int num_steps{static_cast<int>(1e9)};
        double pi{};
        double sum{0.0};
        double step{1.0/num_steps};

        std::println("With No Threading");
        auto start_time{std::chrono::steady_clock::now()};
        for(int i = 0;i<num_steps;++i){
                double x = (i+0.5)*step;
                sum += 4.0/(1.0+x*x);
        }
        pi = step*sum;
        auto end_time{std::chrono::steady_clock::now()};
        auto exec_time{end_time-start_time};
        std::chrono::duration<double, std::milli> ms{exec_time};
        std::println("Execution Time: {}", ms);
        std::println("Pi (Serial): {}", pi);

        sum = 0.0;
        std::println("With Threading");
        start_time = std::chrono::steady_clock::now();
        #pragma omp parallel for reduction(+:sum)
        for(int i = 0;i<num_steps;++i){
                double x = (i+0.5)*step;
                sum += 4.0/(1.0+x*x);
        }
        pi = step*sum;
        end_time = std::chrono::steady_clock::now();
        exec_time = end_time-start_time;
        ms = exec_time;
        std::println("Execution Time: {}", ms);
        std::println("Pi (Parallel): {}", pi);
        return 0;
}
