# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD: head/net-im/gajim/Makefile 319394 2013-05-29 22:28:28Z rm $

PORTNAME=	gajim
PORTVERSION=	0.15.4
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://gajim.org/downloads/0.15/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Jabber client based on a plugin system

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1 \
		${PYTHON_PKGNAMEPREFIX}sexy>=0:${PORTSDIR}/x11-toolkits/py-sexy
LIB_DEPENDS=	gupnp-igd:${PORTSDIR}/net/gupnp-igd

USE_BZIP2=	yes
USES=		gmake pathfix
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_XORG=	x11 xext xscrnsaver
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	src/plugins/plugins_i18n.py
INSTALLS_ICONS=	yes
MAN1=		gajim.1 gajim-remote.1 gajim-history-manager.1

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS NLS AVAHI CRYPTO DBUS KEYRING SPELL
OPTIONS_DEFAULT=DBUS CRYPTO KEYRING SPELL
CRYPTO_DESC=	End to end encryption support
KEYRING_DESC=	Gnome Keyring support
SPELL_DESC=	Spell checking support

PORTDOCS=	AUTHORS ChangeLog README.html

OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MAVAHI}
RUN_DEPENDS+=	avahi-discover:${PORTSDIR}/net/py-avahi
.endif

.if ${PORT_OPTIONS:MDBUS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
.endif

.if ${PORT_OPTIONS:MCRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
.endif

.if ${PORT_OPTIONS:MKEYRING}
USE_GNOME+=	pygnomedesktop
.endif

.if ${PORT_OPTIONS:MSPELL}
LIB_DEPENDS=	gtkspell:${PORTSDIR}/textproc/gtkspell
.endif

pre-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
