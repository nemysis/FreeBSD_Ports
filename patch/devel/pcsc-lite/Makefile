# Created by: Toni Andjelkovic <toni@soth.at>
# $FreeBSD: head/devel/pcsc-lite/Makefile 312209 2013-02-14 09:42:12Z gahr $

PORTNAME=	pcsc-lite
PORTVERSION=	1.8.8
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	devel security
MASTER_SITES=	https://alioth.debian.org/frs/download.php/3862/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Smartcard development library

LICENSE=	BSD

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USES=		pathfix pkgconfig
USE_RC_SUBR=	pcscd

USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers/

SUB_FILES=	pkg-message

MAN1=		pcsc-spy.1
MAN5=		reader.conf.5
MAN8=		pcscd.8

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog DRIVERS HELP README SECURITY TODO

PORTEXAMPLES=	Makefile.am Makefile.in pcsc_demo.c

OPTIONS_DEFINE=	USB CCID

USB_DESC=	Adds devel/libusb support for USB devices
CCID_DESC=	Enable USB CCID support

OPTIONS_DEFAULT=	USB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ENV+=	LIBUSB_LIBS="-lusb"
CONFIGURE_ARGS+=--enable-libusb=/usr
.endif

.if ${PORT_OPTIONS:MCCID}
RUN_DEPENDS+=	RSA_SecurID_getpasswd:${PORTSDIR}/devel/libccid
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^datadir|#datadir|; s|^data_DATA|#data_DATA|" \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e "s|libusb-1.0/libusb.h|libusb.h|; \
		s|libusb_strerror(ret)|ret|" ${WRKSRC}/configure \
			${WRKSRC}/src/hotplug_libusb.c
	@${REINPLACE_CMD} -e "s|-ldl||" ${WRKSRC}/src/spy/Makefile.in

.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^install-data-am: / s|install-docDATA||' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${PREFIX}/lib/pcsc/drivers
	@${MKDIR} ${PREFIX}/lib/pcsc/services
	${TOUCH} ${PREFIX}/lib/pcsc/drivers/.keep_me
	${TOUCH} ${PREFIX}/lib/pcsc/services/.keep_me

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/doc/example/|} ${EXAMPLESDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
