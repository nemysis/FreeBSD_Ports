# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	farstream
PORTVERSION=	0.2.3
CATEGORIES=	net-im devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/releases/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LICENSE=	LGPL21

LIB_DEPENDS=	libnice.so:${PORTSDIR}/net-im/libnice

#CONFLICTS=	farstream-[0-9]*

USES=		gmake gettext pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	glib20 ltverhack
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README

DOCSRCDIR2=	${WRKSRC}/doc

.include <bsd.port.mk>
