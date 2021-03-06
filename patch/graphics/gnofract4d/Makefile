# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD: head/graphics/gnofract4d/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	gnofract4d
PORTVERSION=	3.14.1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Weird GNOME fractal generator

LICENSE=	BSD

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

Uses=		desktop-file-utils pathfix shared-mime-info
USE_GNOME=	gnomeprefix intlhack \
		libgnomeui lthack pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

CFLAGS+=	-I${LOCALBASE}/include
PORTDOCS=	README
INSTALLS_EGGINFO=	yes

.include <bsd.port.options.mk>

post-patch:
	# contain in DATADIR
	# ('share/foobar/gnofract4d' -> # 'share/gnofract4d/foobar')
	@${FIND} ${WRKSRC} -name '*.py' -exec \
		${REINPLACE_CMD} \
		-e "s,\([\"']\)share/\([^/]*\)/gnofract4d\1,\1${DATADIR:C/${PREFIX}\///}/\2\1," {} \;

	# fix PORTDOCS
	${REINPLACE_CMD} -e '249,251d' ${WRKSRC}/setup.py

	# fixup library detection
	@${REINPLACE_CMD} \
		-e "s,/usr/include/jpeglib.h,${LOCALBASE}/include/jpeglib.h," \
		-e "s,/usr/include/gmp.h,${LOCALBASE}/include/gmp.h," \
		${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
