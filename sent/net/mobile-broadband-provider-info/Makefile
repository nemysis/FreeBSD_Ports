# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	mobile-broadband-provider-info
PORTVERSION=	20130312
CATEGORIES=	net
MASTER_SITES=	DEBIAN \
		http://archive.ubuntu.com/ubuntu/pool/main/m/${PORTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Mobile broadband settings for different service provider

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	libxml2
USES=		pathfix
GNU_CONFIGURE=	yes

PLIST_FILES=	libdata/pkgconfig/mobile-broadband-provider-info.pc \
		%%DATADIR%%/serviceproviders.2.dtd \
		%%DATADIR%%/serviceproviders.xml
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	MAINTAINERS NEWS README README.svn

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
