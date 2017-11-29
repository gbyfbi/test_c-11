#include <iostream>
#include <memory>
#include <map>
#include <string>

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto a = {3423,555,6, 000, 1234};

    int b[4] = {2,3,4,5};
    std::shared_ptr<int> pInt(new int[4] {2,3,4,5}, std::default_delete<int[]>());
//    auto pInt = new int[5]{2,3,4,5};
//    std::shared_ptr<int> pInt = std::make_shared<int>(b);
//    auto pInt = std::make_shared<int*>(b);
//    auto pInt = std::make_shared<int[4]>(b);
    int * c = std::move(b);
    for (auto item : b) {
        printf("%d\n", item);
    }
//    for (auto item: pInt) {
//        printf(" %d\n", item);
//    }
    std::map<std::string, std::string> nameToAgeMap{{"gby", "88"}};
    nameToAgeMap["dadfasfd"] = "ddddd";
    for (auto item: nameToAgeMap) {
        std::cout<<item.first<<"-->"<<item.second<<std::endl;
    }
    auto nameToAgeMapMoved = std::move(nameToAgeMap);
    nameToAgeMapMoved["haha"] = "kdasdfjldas;fkjdlsafjd;lasfj";
    for (auto item: nameToAgeMapMoved) {
        std::cout<<item.first<<"-->"<<item.second<<std::endl;
    }
    auto pIntA = std::move(pInt);
    for (int i = 0; i < 4; i++) {
//        printf(" %d\n", *pInt); // wrong
    }
    auto ar = {2,3,3,54, 5, 4999};
    for (auto a : ar) {
        printf("%d\n", a);
    }
    for (auto it = ar.begin(); it != ar.end(); it++) {
        printf("%d\n", *it);
    }
    std::map<std::string, int> nameToWeightMap = {{"gby", 90}};
//    auto m = {{"gby", 90}}; // wrong
//    auto m = {{12, 90}}; // wrong

    return 0;
}