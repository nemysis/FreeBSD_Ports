# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/ampasCTL/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	ampasCTL
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	GH
DISTNAME=	ctl-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Color Transformation Language interpreter

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase

WRKSRC=		${WRKDIR}/ampas-CTL-${GH_COMMIT}/CTL

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ca179ca

USES=		pathfix pkgconfig
PATHFIX_MAKEFILEIN=	 Makefile.am
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/OpenEXR2
# --with-ilmbase-prefix=${PREFIX}/lib/ilmbase2
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README
DOC_FILES2=	CtlManual.pdf CtlManual.doc

.include <bsd.port.options.mk>

test check:	build
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap)

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/CTL-@CTL_VERSION@|$$(datadir)/doc/${PORTNAME}|' \
		${WRKSRC}/doc/Makefile.am

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|CtlManual.pdf CtlManual.doc||' \
		${WRKSRC}/doc/Makefile.am
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
