#define ProtocolInfo 0x01  /*Status of the protocol behaviour, protocol version*/
#define ConfigureProtocol 0x02  /*Tweak the Protocol, e.g. the behaviour of the DRDY pin, behaviour of the pipes*/
#define ControlPipe 0x03 /*Used to send control messages to the module*/
#define PipeStatus 0x04  /*Provides status information for the read pipes*/
#define NotificationPipe 0x05  /*Used to read non-measurement data: errors acknowledgements and other notifications from the module*/
#define MeasurementPipe 0x06  /*All measurement data generated by the module will be available in the measurement pipe*/
