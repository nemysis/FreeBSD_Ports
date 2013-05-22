# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/ampasCTL/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	ampasCTL
PORTVERSION=	1.4.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME:L}/ctl/ctl-${PORTVERSION}/
DISTNAME=	ctl-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Color Transformation Language interpreter

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

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

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/CTL-@CTL_VERSION@|$$(datadir)/doc/ampasCTL|' \
		${WRKSRC}/doc/Makefile.in

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|CtlManual.pdf CtlManual.doc||' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
