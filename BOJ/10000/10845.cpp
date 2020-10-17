#include <iostream>
#include <queue>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a, pushN;
    std::queue<int> q;
    std::string str = "";
    std::cin >> a;
    std::cin.clear();
    std::cin.ignore();
    for(int i = 0; i < a; i++) {
        str = "";
        std::cin >> str;

        if(str == "push") {
            std::cin >> pushN;
            q.push(pushN);
        }
        else if (str == "pop") {
            if(q.size()) {
                std::cout << q.front() << "\n";
                q.pop();
            }
            else
                std::cout << "-1" << "\n";
        }
        else if (str == "size")
            std::cout << q.size() << "\n";
        else if (str == "empty")
            std::cout << q.empty() << "\n";
        else if (str == "front")
            q.size() ? (std::cout << q.front() << "\n") : (std::cout << -1 << "\n");
        else if (str == "back")
            q.size() ? (std::cout << q.back() << "\n") : (std::cout << -1 << "\n");
        else 
            std::cout << "Error" << "\n";
    }
}