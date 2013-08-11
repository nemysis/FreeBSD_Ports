# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	libav
PORTVERSION=	9.8
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	https://libav.org/releases/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform solution to record, convert and stream audio and video

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils \
		texi2html:${PORTSDIR}/textproc/texi2html \
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeSerif.ttf:${PORTSDIR}/x11-fonts/freefont-ttf

USES=		gmake pkgconfig
WANT_SDL=	yes
USE_PERL5_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix="${PREFIX}" --mandir="${PREFIX}/man" --incdir="${PREFIX}/include/${PORTNAME}" \
		--libdir="${PREFIX}/lib/${PORTNAME}" --shlibdir="${PREFIX}/lib/${PORTNAME}" --datadir="${DATADIR}" \
		--enable-gpl --enable-runtime-cpudetect --enable-avcodec --enable-avformat --enable-avutil \
		--enable-swscale --enable-avfilter --enable-avresample \
		--enable-pthreads --enable-network --enable-memalign-hack
ALL_TARGET=	all
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	avconv.1 avprobe.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS Changelog

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	APIchanges RELEASE_NOTES *.txt

OPTIONS_DEFINE=	DOCS SMALL GRAY X11GRAB VAAPI VDPAU FREI0R LIBBLURAY \
		CDIO LIBDC1394 FAAC FDK_AAC FREETYPE GSM LAME AMR_NB AMR_WB \
		OPENCV OPENJPEG OPUS ALSA PULSEAUDIO RTMP SCHROEDINGER SPEEX \
		THEORA VO_AACENC VO_AMRWBENC VORBIS SDL V4L VPX X264 XVID \
		DEBUG OPTIMIZED_CFLAGS

OPTIONS_DEFAULT=	SHARED X11GRAB FREI0R CDIO FREETYPE OPENCV OPENJPEG \
			OPUS RTMP SCHROEDINGER SPEEX THEORA VORBIS SDL V4L VPX \
			X264 XVID OPENSSL

OPTIONS_SINGLE=	SSL LIBRARIES
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_SINGLE_LIBRARIES=	STATIC SHARED

OPTIONS_SUB=	yes

STATIC_DESC=	Build static libraries, avserver (unmaintained)
SHARED_DESC=	Build shared libraries
SMALL_DESC=	Optimize for size instead of speed
GRAY_DESC=	Full grayscale support (slower color)
CPU_DETECTION_DESC=	Detect cpu capabilities at runtime (bigger binary)
X11GRAB_DESC=	X11 grabbing
CDIO_DESC=	Audio CD grabbing with libcdio
LIBDC1394_DESC=	IIDC-1394 grabbing using libdc1394
FDK_AAC_DESC=	AAC encoding via libfdk-aac
AMR_NB_DESC=	AMR-NB de/encoding via libopencore-amrnb
AMR_WB_DESC=	AMR-WB decoding via libopencore-amrwb
OPUS_DESC=	Opus decoding via libopus

DOCS_CONFIGURE_ENABLE=		doc
STATIC_CONFIGURE_ENABLE=	static
SHARED_CONFIGURE_ENABLE=	shared
GNUTLS_CONFIGURE_ENABLE=	gnutls
GNUTLS_LIB_DEPEND=		gnutls:${PORTSDIR}/security/gnutls
OPENSSL_CONFIGURE_ENABLE=	openssl
SMALL_CONFIGURE_ENABLE=		small
GRAY_CONFIGURE_ENABLE=		gray
X11GRAB_CONFIGURE_ENABLE=	x11grab
VAAPI_CONFIGURE_ENABLE=		vaapi
VAAPI_LIB_DEPENDS=		va:${PORTSDIR}/multimedia/libva
VDPAU_CONFIGURE_ENABLE=		vdpau
VDPAU_LIB_DEPENDS=		vdpau:${PORTSDIR}/multimedia/libvdpa
FREI0R_CONFIGURE_ENABLE=	frei0r
FREI0R_BUILD_DEPENDS=		${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
CDIO_CONFIGURE_ENABLE=		libcdio
CDIO_LIB_DEPENDS=		cdio:${PORTSDIR}/sysutils/libcdio
LIBBLURAY_LIB_DEPENDS=		bluray:${PORTSDIR}/multimedia/libbluray
LIBDC1394_CONFIGURE_ENABLE=	libdc1394
LIBDC1394_LIB_DEPENDS=		dc1394:${PORTSDIR}/multimedia/libdc1394
FAAC_CONFIGURE_ENABLE=		libfaac
FAAC_LIB_DEPENDS=		faac:${PORTSDIR}/audio/faac
FDK_AAC_CONFIGURE_ENABLE=	libfdk-aac
FDK_AAC_LIB_DEPENDS=		fdk-aac:${PORTSDIR}/audio/fdk-aac
FREETYPE_CONFIGURE_ENABLE=	libfreetype
FREETYPE_LIB_DEPENDS=		freetype:${PORTSDIR}/print/freetype2
GSM_CONFIGURE_ENABLE=		libgsm
GSM_LIB_DEPENDS=		gsm:${PORTSDIR}/audio/gsm
LAME_CONFIGURE_ENABLE=		libmp3lame
LAME_LIB_DEPENDS=		mp3lame:${PORTSDIR}/audio/lame
AMR_NB_CONFIGURE_ENABLE=	libopencore-amrnb
AMR_NB_LIB_DEPENDS=		opencore-amrnb:${PORTSDIR}/audio/opencore-amr
AMR_WB_CONFIGURE_ENABLE=	libopencore-amrwb
AMR_WB_LIB_DEPENDS=		opencore-amrwb:${PORTSDIR}/audio/opencore-amr
OPENCV_CONFIGURE_ENABLE=	libopencv
OPENCV_LIB_DEPENDS=		opencv_objdetect:${PORTSDIR}/graphics/opencv
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg
OPENJPEG_LIB_DEPENDS=		openjpeg:${PORTSDIR}/graphics/openjpeg
OPUS_CONFIGURE_ENABLE=		libopus
OPUS_LIB_DEPENDS=		opus:${PORTSDIR}/audio/opus
ALSA_LIB_DEPENDS=		asound:${PORTSDIR}/audio/alsa-lib
PULSEAUDIO_CONFIGURE_ENABLE=	libpulse
PULSEAUDIO_LIB_DEPENDS=		pulse:${PORTSDIR}/audio/pulseaudio
RTMP_CONFIGURE_ENABLE=		librtmp
RTMP_LIB_DEPENDS=		rtmp:${PORTSDIR}/multimedia/rtmpdump
SCHROEDINGER_CONFIGURE_ENABLE=	libschroedinger
SCHROEDINGER_LIB_DEPENDS=	schroedinger:${PORTSDIR}/multimedia/schroedinger
SPEEX_CONFIGURE_ENABLE=		libspeex
SPEEX_LIB_DEPENDS=		speex:${PORTSDIR}/audio/speex
THEORA_CONFIGURE_ENABLE=	libtheora
THEORA_LIB_DEPENDS=		theora:${PORTSDIR}/multimedia/libtheora
VO_AACENC_CONFIGURE_ENABLE=	libvo-aacenc
VO_AACENC_LIB_DEPENDS=		vo-aacenc:${PORTSDIR}/audio/vo-aacenc
VO_AMRWBENC_CONFIGURE_ENABLE=	libvo-amrwbenc
VO_AMRWBENC_LIB_DEPENDS=	vo-amrwbenc:${PORTSDIR}/audio/vo-amrwben
VORBIS_CONFIGURE_ENABLE=	libvorbis
VORBIS_LIB_DEPENDS=		vorbis:${PORTSDIR}/audio/libvorbis
SDL_CONFIGURE_ENABLE=		avplay
V4L_LIB_DEPENDS=		v4l2:${PORTSDIR}/multimedia/libv4l
VPX_CONFIGURE_ENABLE=		libvpx
VPX_LIB_DEPENDS=		vpx:${PORTSDIR}/multimedia/libvpx
X264_CONFIGURE_ENABLE=		libx264
X264_LIB_DEPENDS=		x264:${PORTSDIR}/multimedia/x264
XVID_CONFIGURE_ENABLE=		libxvid
XVID_LIB_DEPENDS=		xvidcore:${PORTSDIR}/multimedia/xvid
DEBUG_CONFIGURE_ENABLE=		debug
OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSTATIC}
USE_RC_SUBR=	avserver
MAN1+=		avserver.1
CONFIGURE_ARGS+=	--enable-avserver
.else
CONFIGURE_ARGS+=	--disable-avserver
.endif

.if ${PORT_OPTIONS:MOPENSSL}
LIBAV_NONFREE=	yes
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MX11GRAB}
USE_XORG=	x11 xext xfixes
.endif

.if ${PORT_OPTIONS:MFAAC}
LIBAV_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MFDK_AAC}
LIBAV_NONFREE=	yes
.endif

.if ${PORT_OPTIONS:MAMR_NB}
GPL3=	yes
.endif

.if ${PORT_OPTIONS:MAMR_WB}
GPL3=	yes
.endif

.if ! ${PORT_OPTIONS:MALSA}
CONFIGURE_ARGS+=	--disable-indev=alsa --disable-outdev=alsa
.endif

.if ${PORT_OPTIONS:MVO_AACENC}
GPL3=	yes
.endif

.if ${PORT_OPTIONS:MVO_AMRWBENC}
GPL3=	yes
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
MAN1+=		avplay.1
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.endif

.if defined(GPL3)
CONFIGURE_ARGS+=	--enable-version3
LICENSE+=	GPLv3 LGPL3
.endif

.if defined(LIBAV_NONFREE)
CONFIGURE_ARGS+=	--enable-nonfree
RESTRICTED=	linking to libfaac restricts redistribution
.endif

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|$$(NAME).pc|$$(NAME)-${PORTNAME}.pc|g' \
		-e 's|install-lib$$(NAME)-pkgconfig|install-lib$$(NAME)-${PORTNAME}-pkgconfig|g' \
		${WRKSRC}/library.mak
	@${REINPLACE_CMD} -e 's|arch_default=$$(uname -m)|arch_default=$$(uname -p)|' \
		-e 's|-ldl||' \
		-e 's|gsm/gsm.h|gsm.h|' \
		-e 's|check_header linux/fb.h|#check_header linux/fb.h|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include <SDL|#include <SDL/SDL|' \
		${WRKSRC}/avplay.c
	@${REINPLACE_CMD} -e 's|/etc/avserver.conf|${PREFIX}/etc/avserver.conf|' \
		${WRKSRC}/avserver.c
	@${FIND} ${WRKSRC}/doc -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont/|${LOCALBASE}/lib/X11/fonts/freefont-ttf/|g'
	@${REINPLACE_CMD} -e 's|install-progs-$$(CONFIG_DOC)|#install-progs-$$(CONFIG_DOC)|' \
		${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin/perl -w|${PERL}|' \
		${WRKSRC}/doc/texi2pod.pl
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/libavcodec/libgsm.c

.if ! ${PORT_OPTIONS:MV4L}
	@${REINPLACE_CMD} -i '' '/check_header linux/videodev2.h/,/check_struct linux/videodev2.h/s/^/#/' \
		${WRKSRC}/configure
.endif

post-configure:
.for d in libavcodec libavdevice libavfilter libavformat libavresample libavutil libswscale
	@(cd ${WRKSRC}/${d} ; ${CP} -a ${d}.pc ${d}-${PORTNAME}.pc)
.endfor

post-install:
.if ${PORT_OPTIONS:MSTATIC}
	${INSTALL_DATA} ${WRKSRC}/doc/avserver.conf ${PREFIX}/etc/avserver.conf.sample
	@[ -f ${PREFIX}/etc/avserver.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/doc/avserver.conf ${PREFIX}/etc/avserver.conf
.endif

	(cd ${WRKSRC}/doc ; ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1)

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.post.mk>
