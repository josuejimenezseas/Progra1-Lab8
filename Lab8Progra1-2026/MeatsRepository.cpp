#include "MeatsRepository.h"
#include <stdexcept>
#include <fstream>

MeatsRepository::MeatsRepository() {
    auto data = DataLoader::LoadFromFile("meats.txt");
    data_ = std::move(data);
}

int MeatsRepository::GetAvailableQuantity(const std::string& ingredientType) const {
    auto it = data_.find(ingredientType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de carne desconocido: " + ingredientType);
    }
    return std::stoi(it->second[0]);
}
void MeatsRepository::UpdateQuantity(const std::string& ingredientType, int newQuantity) {
    auto it = data_.find(ingredientType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de carne desconocido: " + ingredientType);
    }
    it->second[0] = std::to_string(newQuantity);

    // Persistencia: reescribir meats.txt con los datos actualizados
    std::ofstream file("meats.txt");
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo escribir meats.txt");
    }
    for (const auto& par : data_) {
        file << par.first << ": " << par.second[0] << "\n";
    }
}
