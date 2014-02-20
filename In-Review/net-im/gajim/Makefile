# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD: head/net-im/gajim/Makefile 345154 2014-02-19 21:45:51Z rm $

PORTNAME=	gajim
PORTVERSION=	0.15.4
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://gajim.org/downloads/0.15/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Jabber client based on a plugin system

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

USE_BZIP2=	yes
USES=		dos2unix gmake pathfix
DOS2UNIX_FILES=	src/plugins/plugins_i18n.py
USE_GNOME=	pygtk2
USE_XORG=	x11 xext xscrnsaver
USE_PYTHON=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+= PYTHON=${PYTHON_CMD}
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	AVAHI  DBUS DOCS E2EE GUPNP KEYRING NLS SPELL
OPTIONS_DEFAULT=DBUS SPELL
OPTIONS_SUB=	yes

E2EE_DESC=	End to End message Encryption suport
KEYRING_DESC=	Gnome Keyring support
GUPNP_DESC=	UPnP IGD protocol support
SPELL_DESC=	Spell checking support

AVAHI_RUN_DEPENDS=	avahi-discover:${PORTSDIR}/net/py-avahi
E2EE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.2:${PORTSDIR}/devel/py-dbus
GUPNP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gupnp/__init__.py:${PORTSDIR}/net/gupnp-igd
KEYRING_USE=		GNOME=pygnomedesktop
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
SPELL_LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell

PORTDOCS=	AUTHORS ChangeLog README.html

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(pkgdatadir)/icons|${PREFIX}/share/icons|; \
		s|$$(datadir)/icons|${PREFIX}/share/icons|' \
		${WRKSRC}/icons/Makefile.in

.if ! ${PORT_OPTIONS:ME2EE}
	@${REINPLACE_CMD} -e 's|PYCRYPTO = True|PYCRYPTO = False|' \
		${WRKSRC}/src/common/gajim.py
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__common__resolver.py
.endif

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/src
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}/src

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
