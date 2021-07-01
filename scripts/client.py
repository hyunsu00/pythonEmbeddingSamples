# client.py
import logging
import logging.handlers


class JsonSocketHandler(logging.handlers.SocketHandler):
    def __init__(self, host, port):
        super().__init__(host, port)

    def makePickle(self, record) -> bytes:
        return super().makePickle(record)


def main():
    rootLogger = logging.getLogger('')
    rootLogger.setLevel(logging.DEBUG)

    """
    # 기본 소켓 핸들러
    socketHandler = logging.handlers.SocketHandler(
        'localhost',
        logging.handlers.DEFAULT_TCP_LOGGING_PORT
    )
    """
    # """
    # Json 소켓 핸들러
    socketHandler = JsonSocketHandler(
        'localhost', logging.handlers.DEFAULT_TCP_LOGGING_PORT
    )
    # """

    # don't bother with a formatter, since a socket handler sends the event as
    # an unformatted pickle
    rootLogger.addHandler(socketHandler)

    # Now, we can log to the root logger, or any other logger. First the root...
    logging.info('Jackdaws love my big sphinx of quartz.')

    # Now, define a couple of other loggers which might represent areas in your
    # application:

    logger1 = logging.getLogger('myapp.area1')
    logger2 = logging.getLogger('myapp.area2')

    logger1.debug('Quick zephyrs blow, vexing daft Jim.')
    logger1.info('How quickly daft jumping zebras vex.')
    logger2.warning('Jail zesty vixen who grabbed pay from quack.')
    logger2.error('The five boxing wizards jump quickly.')


if __name__ == '__main__':
    main()
