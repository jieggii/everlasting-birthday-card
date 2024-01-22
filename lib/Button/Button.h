#ifndef EVERLASTING_BIRTHDAY_CARD_BUTTON_H
#define EVERLASTING_BIRTHDAY_CARD_BUTTON_H


class Button {
public:
    explicit Button(uint8_t pin);

    void initPin() const;

    bool isPressed() const;

private:
    uint8_t pin;
};


#endif //EVERLASTING_BIRTHDAY_CARD_BUTTON_H
