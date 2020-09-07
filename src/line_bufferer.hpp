#pragma once

class LineBufferer
{
private:
    const char *path;
public:
    class LineBufferProcessor;

    LineBufferer(const char *path);
    void Buffer(LineBufferProcessor &line_buffer_processor);

    class LineBufferProcessor
    {
    public:
        virtual void Process(const char *line);
    };
};
