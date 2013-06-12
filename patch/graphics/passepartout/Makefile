# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD: head/graphics/passepartout/Makefile 314640 2013-03-19 13:04:30Z eadler $
#    $MCom: ports/graphics/passepartout/Makefile,v 1.4 2006/09/30 15:31:05 ahze Exp $

PORTNAME=	passepartout
PORTVERSION=	0.7.1
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DTP application for X

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
LIB_DEPENDS=	xml++-2.6:${PORTSDIR}/textproc/libxml++26 \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26
RUN_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USES=		pathfix
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	FAM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFAM}
USE_FAM=	yes
.endif

.if ${PORT_OPTIONS:MDOCS}
MAN1=		xml2ps.1 passepartout.1x
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
