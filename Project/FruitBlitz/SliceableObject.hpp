#ifndef SLICEABLEOBJECT_HPP
#define SLICEABLEOBJECT_HPP

class SliceableObject {
public:
    float x, y;
    float sx, sy;

    SliceableObject(float px, float py, float sx, float sy);
    virtual ~SliceableObject() {}

    virtual void draw() const = 0;
    virtual bool checkCollision(int mouseX, int mouseY) const = 0;
    virtual void slice() = 0;
};

#endif // SLICEABLEOBJECT_HPP
