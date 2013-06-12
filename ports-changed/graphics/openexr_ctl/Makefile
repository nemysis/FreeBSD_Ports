# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/openexr_ctl/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	openexr_ctl
PORTVERSION=	1.0.1
CATEGORIES=	graphics devel
#MASTER_SITES=	SF/ampasctl/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
MASTER_SITES=	GH

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simplified OpenEXR interface to CTL

LICENSE=	BSD

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		IlmCtl:${PORTSDIR}/graphics/ampasCTL

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL
GH_COMMIT=	ca179ca

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog README

.include <bsd.port.options.mk>

test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
