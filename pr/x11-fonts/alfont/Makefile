# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alfont
PORTVERSION=	209
CATEGORIES=	x11-fonts
MASTER_SITES=	http://opensnc.sourceforge.net/alfont/mirror/ \
		http://opensnc.sourceforge.net/alfont/:opensnc
DISTFILES=	AlFont${DISTVERSION}.rar \
		alfont.c:opensnc
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	AlFont${DISTVERSION}.rar

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Wrapper around the freetype2 library

LICENSE=	FTL
LICENSE_NAME=	The FreeType Project LICENSE (FTL)
LICENSE_FILE=	${WRKSRC}/docs/FTL.txt
LICENSE_PERMS=	auto-accept

EXTRACT_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar
LIB_DEPENDS=	alleg.4:${PORTSDIR}/devel/allegro-devel \
		freetype:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake iconv
USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-Iinclude -I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 $$(freetype-config --cflags)
LDFLAGS+=	-L${LOCALBASE}/lib -lalleg $$(freetype-config --libs)

PLIST_FILES=	include/alfont.h \
		include/alfontdll.h \
		lib/libalfont.so.${MAJORVER} \
		lib/libalfont.so

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGES.txt README.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	ALFONT.txt AUTHORS.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

MAJORVER=	${PORTVERSION:S/209/2.0.9/}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && unrar x -y -idq ${_DISTDIR}/AlFont${DISTVERSION}.rar

post-patch:
	@${CP} -af ${_DISTDIR}/alfont.c ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's|ugetxc((char\*\*)|ugetxc((const char\*\*)|' \
		${WRKSRC}/src/alfont.c

	@${REINPLACE_CMD} \
		-e 's|#define ALFONT_WINDOWS|//#define ALFONT_WINDOWS|' \
		-e 's|//#define ALFONT_LINUX|#define ALFONT_LINUX|' \
		${WRKSRC}/include/alfont.h

do-build:
	cd ${WRKSRC} ; ${CC} ${CPPFLAGS} -fPIC -DPIC -c src/alfont.c -o src/alfont.o
	cd ${WRKSRC} ; ${CC} -shared ${LDFLAGS} src/alfont.o -o libalfont.so.${MAJORVER}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libalfont.so.${MAJORVER} ${PREFIX}/lib
	@cd ${PREFIX}/lib ; ${LN} -sf libalfont.so.${MAJORVER} libalfont.so
	${INSTALL_DATA} ${WRKSRC}/include/alfont*.h ${PREFIX}/include

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
