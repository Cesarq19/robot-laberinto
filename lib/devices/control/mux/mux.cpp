#include "mux.h"

Mux::Mux(uint8_t address) : _address(address) {
    _address = address;
}

void Mux::begin() {
    Wire.begin();
}

void Mux::selectChannel(uint8_t channel) {
    if (channel > 7) {
        return; // Invalid channel, do nothing
    }
    uint8_t mask = 1 << channel;
    writeByte(mask);
}

void Mux::enableChannels(uint8_t channels) {
    writeByte(channels);
}

void Mux::disableChannels(uint8_t channels) {
    writeByte(~channels);
}

void Mux::writeByte(uint8_t data) {
    Wire.beginTransmission(_address);
    Wire.write(data);
    Wire.endTransmission();
}
