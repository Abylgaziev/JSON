#include <iostream>
#include <string>
#include <vector>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string&) = 0;
    virtual void EndArray() = 0;
    virtual ~Serializer() {}
};

class JsonSerializer : public Serializer {
public:
    void BeginArray() override {
        std::cout << "[";
    }

    void AddArrayItem(const std::string& item) override {
        if (!elements.empty()) {
            std::cout << ",";
        }
        std::cout << "\"" << item << "\"";
        elements.push_back(item);
    }

    void EndArray() override {
        std::cout << "]";
    }

private:
    std::vector<std::string> elements;
};

int main() {
    
    Serializer* serializer = new JsonSerializer();
    serializer->BeginArray();
    serializer->AddArrayItem("first");
    serializer->AddArrayItem("second");
    serializer->EndArray();
    delete serializer;

    return 0;
}