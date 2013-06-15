# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/openexr_ctl/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	openexr_ctl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/nemysisfreebsdp/
#MASTER_SITES=	GH
DISTNAME=	ctl-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simplified OpenEXR interface to CTL

LICENSE=	BSD

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		IlmCtl:${PORTSDIR}/graphics/ampasCTL

WRKSRC=		${WRKDIR}/ampas-CTL-${GH_COMMIT}/OpenEXR_CTL

#USE_GITHUB=	yes
#GH_ACCOUNT=	ampas
#GH_PROJECT=	CTL
#GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ca179ca

USES=		pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog README

.include <bsd.port.options.mk>

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap)

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
