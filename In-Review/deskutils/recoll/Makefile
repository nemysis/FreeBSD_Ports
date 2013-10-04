# Created by: J.F. Dockes <jean-francois.dockes@wanadoo.fr>
# $FreeBSD: head/deskutils/recoll/Makefile 324744 2013-08-14 22:35:50Z ak $

PORTNAME=	recoll
#PORTVERSION=	1.18.2
PORTVERSION=	1.19.5
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Personal full text search package, based on Xapian

LICENSE=	GPLv2

BUILD_DEPENDS=	xapian-core>=0:${PORTSDIR}/databases/xapian-core

USES=		gmake iconv
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		recollindex.1
MAN5=		recoll.conf.5

OPTIONS_DEFINE=	QT4 ASPELL PYTHON X11MON
X11MON_DESC=	X11 session monitoring support
OPTIONS_DEFAULT=QT4 ASPELL PYTHON X11MON

OPTIONS_SUB=	yes

QT4_CONFIGURE_ON=		qtgui

ASPELL_LIB_DEPENDS=		libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_CONFIGURE_ENABLE=	aspell

PYTHON_CONFIGURE_ENABLE=	python-module

X11MON_CONFIGURE_ENABLE=	x11mon

# Wrong versioning upstream
PORTSCOUT=	skipv:1.19

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats \
		corelib gui xml webkit
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}"
INSTALLS_ICONS=	yes
PLIST_SUB+=	QT=""
MAN1+=		recollq.1 recoll.1
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	Recoll-1.0-py${PYTHON_VER}.egg-info
.endif

.if ${PORT_OPTIONS:MX11MON}
USE_XORG+=	ice sm x11
USE_FAM=	yes
CONFIGURE_ARGS+=--with-fam
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$${MAKE} -C query recollq|@NOQTMAKE@$${MAKE} -C query recollq|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|/usr/local/lib|${LOCALBASE}/lib|' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|= -g -O2|=|' ${WRKSRC}/mk/localdefs.in
	@${REINPLACE_CMD} \
		-e 's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/mk/${OPSYS}
	@${REINPLACE_CMD} -e 's|@NOCMDLINE@|@NOQTMAKE@|g' \
		${WRKSRC}/recollinstall.in

post-configure:
.if ${PORT_OPTIONS:MQT4}
	@cd ${WRKSRC}/qtgui && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}
.endif

.include <bsd.port.mk>
