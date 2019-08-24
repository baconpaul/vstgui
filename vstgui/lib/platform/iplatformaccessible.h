#ifndef __iplatformaccessible__
#define __iplatformaccessible__
namespace VSTGUI
{
    class IPlatformAccessibleElement
    {
    public:
        virtual std::string getAccessibleName() = 0;

        virtual ~IPlatformAccessibleElement() { }

        // This is a hack for now...
        virtual void *getAccData() { return ad; }
        virtual void setAccData( void *u ) { ad = u; }
    private:
        void *ad = nullptr;
    };

    class IPlatformAccessibleContainer : public IPlatformAccessibleElement
    {
    public:
        virtual std::vector<IPlatformAccessibleElement *> getAccessibleChildren() = 0;
    };

    class IPlatformAccessibleControl : public IPlatformAccessibleElement
    {
    public:
    };
}
#endif
