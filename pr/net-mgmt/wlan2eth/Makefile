# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	wlan2eth
PORTVERSION=	1.3
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.willhackforsushi.com/code/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Convert packet captures in 802.11 format to Ethernet format

LICENSE=	GPLv2

PORTDOCS=	THANKS
SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
