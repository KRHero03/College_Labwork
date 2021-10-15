
class Rectangle{
    private:
        double width,length;
    public:
        Rectangle(){
            this->width = 0;
            this->length = 0;
        }
        Rectangle(double x){
            this->width = x;
            this->length = x;
        }
        Rectangle(double length, double width){
            this->width = width;
            this->length = length;
        }
        double getArea(){
            return this->width*this->length;
        }
        double getPerimeter(){
            return 2.0*(this->width + this->length);
        }
};