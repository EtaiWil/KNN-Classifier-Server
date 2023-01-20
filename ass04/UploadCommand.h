class UploadCommand:public Command{
    public:
    UploadCommand(string description,DefaultIO& dio);
    virtual void execute();

};