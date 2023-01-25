#include "UploadCommand.h"

UploadCommand::UploadCommand(CLI &cli, DefaultIO &dio) : Command(cli, "upload an unclassified csv data file", dio)
{
}
// getting from the user the csv files and check if ther  is any problem with them.
void UploadCommand::execute()
{
    // send a message to upload the train vectors
    dio.write("Please upload your local train CSV file.");
    string input, data;
    bool doneRead = false; // read flag to know when the user is finished
    do
    {
        input = dio.read();
        if (!input.empty()) // if the message was not empty
        {
            if (input == "ERRORABORT") // if the user failed to open a file.
            {
                return;
            }
            data.append(input); // add the input to the data string
        }
        std::size_t found = data.find("\n\n"); // the "\n\n is a sign for end of send"
        if (found != std::string::npos)
        {
            data = data.substr(0, found);
            doneRead = true;
        }

    } while (!doneRead);
    // get the data into the train vectors database in the classifier.
    cli.getTrainVectors(data);
    // request the test vectors
    dio.write("Upload complete.\nPlease upload your local test CSV file.");
    // reset the data and the doneread flags
    data = "";
    doneRead = false;
    do
    {
        // get input from the user
        input = dio.read();
        if (!input.empty())
        {
            // if getting the input fails.
            if (input == "ERRORABORT")
            {
                return;
            }
            // add the input to the data string
            data.append(input);
        }
        std::size_t found = data.find("\n\n"); // a sign to know the read was done
        if (found != std::string::npos)
        {
            data = data.substr(0, found);
            doneRead = true;
        }

    } while (!doneRead); // while the flag is off

    cli.getTestVectors(data);        // get the given data to the test vectors database.
    dio.write("Upload complete.\n"); // send the user that reading the data ended.
}
