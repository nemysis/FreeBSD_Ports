# $FreeBSD: head/comms/spandsp-devel/Makefile 318957 2013-05-24 10:46:51Z bapt $

PORTNAME=	spandsp
DISTVERSION=	0.0.6pre21
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	DSP library and software FAX machine

LICENSE=	LGPL21

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/spandsp-${DISTVERSION:C/pre.*//}

USES=		pathfix
USE_AUTOTOOLS=	libtool autoconf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		-C
USE_LDCONFIG=	yes

CONFLICTS=	spandsp-[0-9]*

OPTIONS_DEFINE=	DOXYGEN

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-doc
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt
.else
CONFIGURE_ARGS+=--disable-doc
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${DOCSDIR} "-type d -or -mindepth 1")
.endif

.include <bsd.port.mk>
