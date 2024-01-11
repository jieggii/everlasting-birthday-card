#ifndef EVERLASTING_BIRTHDAY_CARD_BUTTON_H
#define EVERLASTING_BIRTHDAY_CARD_BUTTON_H


class Button {
public:
    Button(unsigned char pin);

    void initPin() const;

    bool isPressed() const;

private:
    unsigned char pin;
};


#endif //EVERLASTING_BIRTHDAY_CARD_BUTTON_H
