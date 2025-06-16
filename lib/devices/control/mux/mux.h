#ifndef MUX_H
#define MUX_H

#include <Wire.h>

class Mux {
    public:
        Mux(uint8_t address);
        void begin();
        void selectChannel(uint8_t channel);
        void enableChannels(uint8_t channels);
        void disableChannels(uint8_t channels);

    private:
        uint8_t _address;
        void writeByte(uint8_t data);
};

#endif // MUX_H