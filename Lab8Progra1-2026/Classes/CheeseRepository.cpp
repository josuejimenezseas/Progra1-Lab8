#include "CheeseRepository.h"
#include <fstream>
#include <stdexcept>

CheeseRepository::CheeseRepository() {
    // Igual que DataLoader: primero busca junto al .exe y si no, en la carpeta Data.
    filePath_ = "cheese.txt";
    std::ifstream test(filePath_);
    if (!test) {
        filePath_ = "Data/cheese.txt";
    }

    auto data = DataLoader::LoadFromFile(filePath_);
    data_ = std::move(data);
}

int CheeseRepository::GetAvailableQuantity(const std::string& cheeseType) const {
    auto it = data_.find(cheeseType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de queso desconocido: " + cheeseType);
    }
    return std::stoi(it->second[0]);
}

void CheeseRepository::UpdateQuantity(const std::string& cheeseType, int newQuantity) {
    auto it = data_.find(cheeseType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de queso desconocido: " + cheeseType);
    }
    it->second[0] = std::to_string(newQuantity);
    SaveToFile();
}

// Guarda todas las cantidades en el archivo con el formato "Nombre: cantidad".
void CheeseRepository::SaveToFile() const {
    std::ofstream out(filePath_);
    for (const auto& item : data_) {
        out << item.first << ": " << item.second[0] << "\n";
    }
}
