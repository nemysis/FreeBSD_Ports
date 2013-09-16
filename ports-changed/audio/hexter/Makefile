# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD: head/audio/hexter/Makefile 322948 2013-07-13 17:23:19Z deischen $

PORTNAME=	hexter
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	SF/dssi/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	DSSI softsynth that models the sound generation of a Yamaha DX7

LICENSE=	GPLv2

LIB_DEPENDS=	dssialsacompat:${PORTSDIR}/audio/libdssialsacompat \
		lo:${PORTSDIR}/audio/liblo \
		jack:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi

USES=		gmake
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
